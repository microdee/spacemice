#include "capabilities.h"
#include "device.h"

namespace spacemice
{
    namespace devices
    {
        button_bits capabilities::map_modern_buttons(button_bits hid_buttons)
        {
            // Source of info: https://github.com/blender/blender/blob/594f47ecd2d5367ca936cf6fc6ec8168c2b360d0/intern/ghost/intern/GHOST_NDOFManager.cpp#L91
            static std::vector<button_type> target_button
            {
                button_type::menuOptions,
                button_type::viewFit,
                button_type::viewTop,
                button_type::viewLeft,
                button_type::viewRight,
                button_type::viewFront,
                button_type::viewBottom,
                button_type::viewBack,
                button_type::viewRollCW,
                button_type::viewRollCCW,
                button_type::viewIso1,
                button_type::viewIso2,
                button_type::keyF1,
                button_type::keyF2,
                button_type::keyF3,
                button_type::keyF4,
                button_type::keyF5,
                button_type::keyF6,
                button_type::keyF7,
                button_type::keyF8,
                button_type::keyF9,
                button_type::keyF10,
                button_type::keyEsc,
                button_type::keyAlt,
                button_type::keyShift,
                button_type::keyCtrl,
                button_type::filterRotate,
                button_type::filterPanzoom,
                button_type::filterDominant,
                button_type::scalePlus,
                button_type::scaleMinus
            };
            return map_buttons(hid_buttons, target_button);
        }

        button_bits capabilities::map_buttons(button_bits hid_buttons, const std::vector<button_type>& to_sm_button)
        {
            button_bits output {};
            for (int i=0; i<to_sm_button.size(); ++i)
            {
                if (hid_buttons[i])
                    output[static_cast<int>(to_sm_button[i])] = true;
            }
            return output;
        }
        space_explorer::space_explorer()
        {
            supported_buttons =
            {
                button_type::keyF1,
                button_type::keyF2,
                button_type::viewTop,
                button_type::viewLeft,
                button_type::viewRight,
                button_type::viewFront,
                button_type::keyEsc,
                button_type::keyAlt,
                button_type::keyShift,
                button_type::keyCtrl,
                button_type::viewFit,
                button_type::menuOptions,
                button_type::scalePlus,
                button_type::scaleMinus,
                button_type::filterRotate,
            };
        }

        void space_explorer::transform_raw_data(device_output& data)
        {
            // Source of info: https://github.com/blender/blender/blob/594f47ecd2d5367ca936cf6fc6ec8168c2b360d0/intern/ghost/intern/GHOST_NDOFManager.cpp#L101
            static std::vector<button_type> target_button
            {
                button_type::keyF1,
                button_type::keyF2,
                button_type::viewTop,
                button_type::viewLeft,
                button_type::viewRight,
                button_type::viewFront,
                button_type::keyEsc,
                button_type::keyAlt,
                button_type::keyShift,
                button_type::keyCtrl,
                button_type::viewFit,
                button_type::menuOptions,
                button_type::scalePlus,
                button_type::scaleMinus,
                button_type::filterRotate,
            };
            data.buttons = map_buttons(data.buttons, target_button);
        }

        space_pilot::space_pilot()
        {
            supported_buttons =
            {
                button_type::keyF1,
                button_type::keyF2,
                button_type::keyF3,
                button_type::keyF4,
                button_type::keyF5,
                button_type::keyF6,
                button_type::viewTop,
                button_type::viewLeft,
                button_type::viewRight,
                button_type::viewFront,
                button_type::keyEsc,
                button_type::keyAlt,
                button_type::keyShift,
                button_type::keyCtrl,
                button_type::menuOptions,
                button_type::viewFit,
                button_type::scalePlus,
                button_type::scaleMinus,
                button_type::filterDominant,
                button_type::filterRotate
            };
        }
        
        void space_pilot::transform_raw_data(device_output& data)
        {
            // Source of info: https://github.com/blender/blender/blob/594f47ecd2d5367ca936cf6fc6ec8168c2b360d0/intern/ghost/intern/GHOST_NDOFManager.cpp#L101
            static std::vector<button_type> target_button
            {
                button_type::keyF1,
                button_type::keyF2,
                button_type::keyF3,
                button_type::keyF4,
                button_type::keyF5,
                button_type::keyF6,
                button_type::viewTop,
                button_type::viewLeft,
                button_type::viewRight,
                button_type::viewFront,
                button_type::keyEsc,
                button_type::keyAlt,
                button_type::keyShift,
                button_type::keyCtrl,
                button_type::menuOptions,
                button_type::viewFit,
                button_type::scalePlus,
                button_type::scaleMinus,
                button_type::filterDominant,
                button_type::filterRotate
                // Blender mentions a config button
            };
            data.buttons = map_buttons(data.buttons, target_button);
        }

        space_pilot_pro::space_pilot_pro()
        {
            supported_buttons =
            {
                // sides
                button_type::menuOptions,
                button_type::viewFit,

                // left
                button_type::keyF1,
                button_type::keyF2,
                button_type::keyF3,
                button_type::keyF4,
                button_type::keyF5,
                button_type::keyF6, // blue ?
                button_type::keyF7, // blue ?
                button_type::keyF8, // blue ?
                button_type::keyF9, // blue ?
                button_type::keyF10, // blue ?

                // left upper
                button_type::keyEsc,
                button_type::keyCtrl,
                button_type::keyAlt,
                button_type::keyShift,

                // right
                button_type::viewRollCW, // ?
                button_type::viewRollCCW, // ? // blue ?
                button_type::viewTop,
                button_type::viewBottom, // blue ?
                button_type::viewRight,
                button_type::viewLeft, // blue ?
                button_type::viewFront,
                button_type::viewBack, // blue ?
                button_type::viewIso1,
                button_type::viewIso2, // blue ?

                // right upper        
                button_type::filterPanzoom, // ?
                button_type::filterDominant, // ?
                button_type::filterRotate, // ?
                button_type::scalePlus, // ?
                button_type::scaleMinus, // ?

                // front
                button_type::keyF1,
                button_type::keyF2,
                button_type::keyF3,
                button_type::keyF4,
                button_type::keyF5,
                button_type::keyF6,
                button_type::keyF7,
                button_type::keyF8,
                button_type::keyF9,
                button_type::keyF10,
                button_type::keyF11,
                button_type::keyF12,
            };
        }
        
        void space_pilot_pro::transform_raw_data(device_output& data)
        {
            data.buttons = map_modern_buttons(data.buttons);
        }
        
        sm_enterprise::sm_enterprise()
        {
            supported_buttons =
            {
                // sides
                button_type::menuOptions,
                button_type::viewFit,
                button_type::keySpace,
                button_type::viewIso1,
                button_type::viewIso2, // blue ?

                // left
                button_type::keyCtrl,
                button_type::keyAlt,
                button_type::keyShift,
                button_type::keyTab, // OOR ?
                button_type::keyEsc,
                button_type::keyEnter, // OOR ?

                // right
                button_type::viewRollCW, // ?
                button_type::viewRollCCW, // ? // blue ?
                button_type::viewTop,
                button_type::viewBottom, // blue ?
                button_type::viewRight,
                button_type::viewLeft, // blue ?
                button_type::viewFront,
                button_type::viewBack, // blue ?
                button_type::filterRotate, // ?

                // right upper // TODO: Out of currently known HID protocol range
                button_type::view1, // ?
                button_type::view2, // ?
                button_type::view3, // ?
                button_type::saveView1, // ? // blue ?
                button_type::saveView2, // ? // blue ?
                button_type::saveView3, // ? // blue ?
                button_type::keyDelete, // OOR ?

                // front
                button_type::keyF1,
                button_type::keyF2,
                button_type::keyF3,
                button_type::keyF4,
                button_type::keyF5,
                button_type::keyF6,
                button_type::keyF7,
                button_type::keyF8,
                button_type::keyF9,
                button_type::keyF10,
                button_type::keyF11,
                button_type::keyF12,
            };
        }
        
        void sm_enterprise::transform_raw_data(device_output& data)
        {
            data.buttons = map_modern_buttons(data.buttons);
        }

        sm_pro::sm_pro()
        {
            supported_buttons =
            {
                // sides
                button_type::menuOptions,
                button_type::viewFit,

                // left
                button_type::keyCtrl,
                button_type::keyAlt,
                button_type::keyShift,
                button_type::keyEsc,

                // right
                button_type::viewRollCW, // ?
                button_type::viewTop,
                button_type::viewRight,
                button_type::viewFront,
                button_type::filterRotate, // ?

                // front
                button_type::keyF1,
                button_type::keyF2,
                button_type::keyF3,
                button_type::keyF4,
            };
        }
        
        void sm_pro::transform_raw_data(device_output& data)
        {
            data.buttons = map_modern_buttons(data.buttons);
        }

        universal_receiver::universal_receiver()
        {
            // TODO: detect actual device and use those buttons
            for (button_type button : all_buttons())
            {
                supported_buttons.emplace(button);
            }
        }

        void universal_receiver::transform_raw_data(device_output& data)
        {
            // TODO: assumption, so far all universal receiver compatible device have the same HID protocol
            // TODO: detect device types through the universal receiver
            data.buttons = map_modern_buttons(data.buttons);
        }
    }
}