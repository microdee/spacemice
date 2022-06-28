#pragma once
#include "spacemice.h"

#include <unordered_set>
#include <vector>

namespace spacemice
{
    namespace devices
    {
        struct device_output;
        
        class capabilities
        {
        public:
            virtual ~capabilities() = default;

            std::unordered_set<button_type> supported_buttons {};
            
            // Source of info: https://github.com/blender/blender/blob/594f47ecd2d5367ca936cf6fc6ec8168c2b360d0/intern/ghost/intern/GHOST_NDOFManager.cpp#L91
            static button_bits map_modern_buttons(button_bits hid_buttons);
            static button_bits map_buttons(button_bits hid_buttons, const std::vector<button_type>& to_sm_button);

            virtual void transform_raw_data(device_output& data) {}
        };

        class space_explorer : public capabilities
        {
            space_explorer();
            virtual void transform_raw_data(device_output& data) override;
        };

        class space_navigator : public capabilities
        {
            space_navigator()
            {
                supported_buttons = {
                    button_type::menuOptions,
                    button_type::viewFit
                };
            }
        };

        class space_pilot : public capabilities
        {
            space_pilot();
            virtual void transform_raw_data(device_output& data) override;
        };

        class space_pilot_pro : public capabilities
        {
            space_pilot_pro();
            virtual void transform_raw_data(device_output& data) override;
        };
        
        class sm_enterprise : public capabilities
        {
            sm_enterprise();
            virtual void transform_raw_data(device_output& data) override;
        };
        
        class sm_pro : public capabilities
        {
            sm_pro();
            virtual void transform_raw_data(device_output& data) override;
        };
        
        class universal_receiver : public capabilities
        {
            universal_receiver();
            virtual void transform_raw_data(device_output& data) override;
        };
    }
}