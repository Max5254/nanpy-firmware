#ifndef NEOPIXEL_CLASS
#define NEOPIXEL_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"
#include <Adafruit_NeoPixel.h>

class NeoPixel;

namespace nanpy {
    class NeoPixelClass: public ObjectsManager<Adafruit_NeoPixel> {
        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();
    };
}

#endif
