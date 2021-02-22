/*
  ==============================================================================

    BiquadFilter.cpp
    Created: 22 Feb 2021 6:24:26pm
    Author:  Davis

  ==============================================================================
*/

#include "BiquadFilter.h"
#include "BiquadFilterCoeffs.h"

using namespace SleepyCat;
using namespace DSP;

MultibandBiquadFilter::MultibandBiquadFilter(int numBands):
m_nNumBands(numBands)
{
	m_pMemory = new float[numBands * 2 + 2];
}

MultibandBiquadFilter::~MultibandBiquadFilter()
{
	delete [] m_pMemory;
}

void MultibandBiquadFilter::Process(float * buffer, int bufferSize, BiquadFilterCoeffs * coeffs, int numBands)
{
	int memoryIndex = 0;
	numBands = (numBands == 0 || numBands > m_nNumBands) ? m_nNumBands : numBands;
	for(int i = 0; i < bufferSize; i++)
	{
		float y = buffer[i];
		for(int band = 0; band < numBands; band++)
		{
			float x = y;
			// multiply and add
			y = y * coeffs[band].getA0 +
				m_pMemory[memoryIndex + 0] * coeffs[band].getA1() +
				m_pMemory[memoryIndex + 1] * coeffs[band].getA2() +
				m_pMemory[memoryIndex + 2] * coeffs[band].getB1() +
				m_pMemory[memoryIndex + 3] * coeffs[band].getB2();

			// shift memory
			m_pMemory[memoryIndex + 1] = m_pMemory[memoryIndex + 0];
			m_pMemory[memoryIndex] = x;

			m_pMemory[memoryIndex + 3] = m_pMemory[memoryIndex + 2];
			m_pMemory[memoryIndex + 2] = y;

			// increment memory location
			memoryIndex += 2;
		}

		// write output
		buffer[i] = y;
	}
}
