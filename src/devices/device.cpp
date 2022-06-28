#include "device.h"

namespace spacemice
{
    namespace devices
    {
        device_output device_output::operator+(const device_output& o) const
        {
            return {
                position_x + o.position_x,
                position_y + o.position_y,
                position_z + o.position_z,

                rotation_x + o.rotation_x,
                rotation_y + o.rotation_y,
                rotation_z + o.rotation_z,
                buttons | o.buttons
            };
        }

        device_output&& device_output::operator+=(const device_output& o)
        {
            position_x += o.position_x;
            position_y += o.position_y;
            position_z += o.position_z;

            rotation_x += o.rotation_x;
            rotation_y += o.rotation_y;
            rotation_z += o.rotation_z;
            buttons |= o.buttons;
            return std::move(*this);
        }
    }
}