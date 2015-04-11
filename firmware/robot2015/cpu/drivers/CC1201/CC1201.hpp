#pragma once

#include "mbed.h"
#include "cmsis_os.h"
#include "CommLink.hpp"
#include "RTP.hpp"
#include "CC1101-Defines.hpp"

class CC1201 : public CommLink
{
	public:
		CC1201();
	
		CC1201(PinName mosi, PinName miso, PinName sck, PinName cs, PinName intPin = NC);

		virtual ~CC1201();

		virtual int32_t sendData(uint8_t* buffer, uint8_t size);

		virtual int32_t getData(uint8_t*, uint8_t*);

		virtual void reset(void);
    
		virtual int32_t selfTest(void);
		    
		virtual bool isConnected(void);

	protected:
		void writeReg(uint8_t addr, uint8_t value);

		void writeReg(uint8_t addr, uint8_t* buffer, uint8_t len);

	private:
		uint8_t strobe(uint8_t);

		uint8_t mode(void);

		uint8_t status(uint8_t addr);
};
