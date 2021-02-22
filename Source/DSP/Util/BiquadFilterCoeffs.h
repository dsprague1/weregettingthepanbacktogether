/*
  ==============================================================================

    BiquadFilterCoeffs.h
    Created: 22 Feb 2021 6:07:26pm
    Author:  Davis

  ==============================================================================
*/

#pragma once

namespace SleepyCat
{
namespace DSP
{
	// A for feedforward, B for feedback
	// assumes normalized
	struct BiquadFilterCoeffs
	{
		enum 
		{
			BiquadA0,
			BiquadA1,
			BiquadA2,
			BiquadB1,
			BiquadB2,
			NumCoeffs
		};

		BiquadFilterCoeffs()
		{
			makePassthrough();
		}

		BiquadFilterCoeffs(float a0, float a1, float a2, float b1, float b2)
		{
			coeffs[BiquadA0] = a0;
			coeffs[BiquadA1] = a1;
			coeffs[BiquadA2] = a2;
			coeffs[BiquadB1] = b1;
			coeffs[BiquadB2] = b2;
		}

		BiquadFilterCoeffs(BiquadFilterCoeffs & coeffs)
		{
			float * data = coeffs.getRawData();
			coeffs[BiquadA0] = data[BiquadA0];
			coeffs[BiquadA1] = data[BiquadA1];
			coeffs[BiquadA2] = data[BiquadA2];
			coeffs[BiquadB1] = data[BiquadB1];
			coeffs[BiquadB2] = data[BiquadB2];
		}

		void makePassthrough() 
		{
			coeffs[BiquadA0] = 1.f;
			coeffs[BiquadA1] = 0;
			coeffs[BiquadA2] = 0;
			coeffs[BiquadB1] = 0;
			coeffs[BiquadB2] = 0;
		}

		float getA0() { return coeffs[BiquadA0]; }
		float getA1() { return coeffs[BiquadA1]; }
		float getA2() { return coeffs[BiquadA2]; }
		float getB1() { return coeffs[BiquadB1]; }
		float getB2() { return coeffs[BiquadB2]; }

		void setA0(float a0) { coeffs[BiquadA0] = a0; }
		void setA1(float a1) { coeffs[BiquadA1] = a1; }
		void setA2(float a2) { coeffs[BiquadA2] = a2; }
		void setB1(float b1) { coeffs[BiquadB1] = b1; }
		void setB2(float b2) { coeffs[BiquadB2] = b2; }

		void updateCoeffs(float a0, float a1, float a2, float b1, float b2)
		{
			coeffs[BiquadA0] = a0;
			coeffs[BiquadA1] = a1;
			coeffs[BiquadA2] = a2;
			coeffs[BiquadB1] = b1;
			coeffs[BiquadB2] = b2;
		}

		float * getRawData() { return &coeffs[0]; }

	private:
		float coeffs[NumCoeffs];
	};
}
}