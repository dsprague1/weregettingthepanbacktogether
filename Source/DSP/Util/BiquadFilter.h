/*
  ==============================================================================

    BiquadFilter.h
    Created: 22 Feb 2021 6:07:13pm
    Author:  Davis

  ==============================================================================
*/

#pragma once

namespace SleepyCat
{
namespace DSP
{
class MultibandBiquadFilter
{
public:
	MultibandBiquadFilter(int numBands);
	~MultibandBiquadFilter();

	void Process(float * buffer, int bufferSize, BiquadFilterCoeffs * coeffs, int numBands = 0);

private:
	const int m_nNumBands;
	float * m_pMemory;
};
}
}