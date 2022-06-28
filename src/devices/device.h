#pragma once
#include "spacemice.h"

#include <memory>
#include <string>

namespace spacemice
{
    class movement_state;

    namespace devices
    {
        class data_reading_method;
        class capabilities;
        class active_hid_device;

        struct device_output
        {
            float position_x;
            float position_y;
            float position_z;

            float rotation_x;
            float rotation_y;
            float rotation_z;

            button_bits buttons;

            device_output operator+(const device_output& o) const;
            device_output&& operator+=(const device_output& o);
        };

        struct device_instantiation
        {
            int internal_id = 0;
            std::shared_ptr<active_hid_device> hid_device;
        };

        class device
        {
        public:
            device(
                const std::string& name_in,
                const model_confidence& confidence_in,
                const std::shared_ptr<capabilities>& capabilities_in,
                const std::shared_ptr<data_reading_method>& reading_method_in,
                const device_instantiation& instance
            );
            ~device();

            std::string name;
            model_confidence confidence;
            int internal_id;
            std::shared_ptr<capabilities> capabilities;
            std::shared_ptr<data_reading_method> reading_method;
            std::shared_ptr<active_hid_device> hid_device;
            std::shared_ptr<device_output> raw_data;
            std::shared_ptr<movement_state> movement;

            void tick();

        private:
            bool inited = false;
            void tick_init();
        };
    }
}