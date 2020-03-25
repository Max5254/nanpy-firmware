#include "cfg.h"

#if USE_NeoPixel

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "NeoPixelClass.h"
#include <stdlib.h>

const char* nanpy::NeoPixelClass::get_firmware_id()
{
    return "NeoPixel";
}

void nanpy::NeoPixelClass::elaborate( MethodDescriptor* m ) {
    ObjectsManager<Adafruit_NeoPixel>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) {
        Adafruit_NeoPixel* strip;
        strip = new Adafruit_NeoPixel (m->getInt(1), m->getInt(0), NEO_GRB + NEO_KHZ800);
        strip->begin();
        strip->show();
        v.insert(strip);
        m->returns(v.getLastIndex());
    }

    if (strcmp(m->getName(), "setPixel") == 0) {
        v[m->getObjectId()]->setPixelColor(m->getInt(0), v[m->getObjectId()]->Color(m->getInt(1),m->getInt(2),m->getInt(3)));
        m->returns(0);
    }

    if (strcmp(m->getName(), "show") == 0) {
        v[m->getObjectId()]->show();
        m->returns(0);
    }
};

#endif
