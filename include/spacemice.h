#pragma once

#include <tuple>
#include <bitset>

namespace spacemice
{
    std::tuple<int, int, int> version();

    typedef std::bitset<256> button_bits;

    enum class button_type
    {
        menuOptions                      = 0,
        viewFit                          = 1,
        viewTop                          = 2,
        viewLeft                         = 3,
        viewRight                        = 4,
        viewFront                        = 5,
        viewBottom                       = 6,
        viewBack                         = 7,
        viewRollCW                       = 8,
        viewRollCCW                      = 9,
        viewIso1                         = 10,
        viewIso2                         = 11,
        keyF1                            = 12,
        keyF2                            = 13,
        keyF3                            = 14,
        keyF4                            = 15,
        keyF5                            = 16,
        keyF6                            = 17,
        keyF7                            = 18,
        keyF8                            = 19,
        keyF9                            = 20,
        keyF10                           = 21,
        keyF11                           = 22,
        keyF12                           = 23,
        keyEsc                           = 24,
        keyAlt                           = 25,
        keyShift                         = 26,
        keyCtrl                          = 27,
        filterRotate                     = 28,
        filterPanzoom                    = 29,
        filterDominant                   = 30,
        scalePlus                        = 31,
        scaleMinus                       = 32,
        viewSpinCW                       = 33,
        viewSpinCCW                      = 34,
        viewTiltCW                       = 35,
        viewTiltCCW                      = 36,
        menuPopup                        = 37,
        menuButtonMappingEditor          = 38,
        menuAdvancedSettingsEditor       = 39,
        motionMacroZoom                  = 40,
        motionMacroZoomOutCursorToCenter = 41,
        motionMacroZoomInCursorToCenter  = 42,
        motionMacroZoomOutCenterToCenter = 43,
        motionMacroZoomInCenterToCenter  = 44,
        motionMacroZoomOutCursorToCursor = 45,
        motionMacroZoomInCursorToCursor  = 46,
        viewQzIn                         = 47,
        viewQzOut                        = 48,
        keyEnter                         = 49,
        keyDelete                        = 50,
        keyF13                           = 51,
        keyF14                           = 52,
        keyF15                           = 53,
        keyF16                           = 54,
        keyF17                           = 55,
        keyF18                           = 56,
        keyF19                           = 57,
        keyF20                           = 58,
        keyF21                           = 59,
        keyF22                           = 60,
        keyF23                           = 61,
        keyF24                           = 62,
        keyF25                           = 63,
        keyF26                           = 64,
        keyF27                           = 65,
        keyF28                           = 66,
        keyF29                           = 67,
        keyF30                           = 68,
        keyF31                           = 69,
        keyF32                           = 70,
        keyF33                           = 71,
        keyF34                           = 72,
        keyF35                           = 73,
        keyF36                           = 74,
        view1                            = 75,
        view2                            = 76,
        view3                            = 77,
        view4                            = 78,
        view5                            = 79,
        view6                            = 80,
        view7                            = 81,
        view8                            = 82,
        view9                            = 83,
        view10                           = 84,
        view11                           = 85,
        view12                           = 86,
        view13                           = 87,
        view14                           = 88,
        view15                           = 89,
        view16                           = 90,
        view17                           = 91,
        view18                           = 92,
        view19                           = 93,
        view20                           = 94,
        view21                           = 95,
        view22                           = 96,
        view23                           = 97,
        view24                           = 98,
        view25                           = 99,
        view26                           = 100,
        view27                           = 101,
        view28                           = 102,
        view29                           = 103,
        view30                           = 104,
        view31                           = 105,
        view32                           = 106,
        view33                           = 107,
        view34                           = 108,
        view35                           = 109,
        view36                           = 110,
        saveView1                        = 111,
        saveView2                        = 112,
        saveView3                        = 113,
        saveView4                        = 114,
        saveView5                        = 115,
        saveView6                        = 116,
        saveView7                        = 117,
        saveView8                        = 118,
        saveView9                        = 119,
        saveView10                       = 120,
        saveView11                       = 121,
        saveView12                       = 122,
        saveView13                       = 123,
        saveView14                       = 124,
        saveView15                       = 125,
        saveView16                       = 126,
        saveView17                       = 127,
        saveView18                       = 128,
        saveView19                       = 129,
        saveView20                       = 130,
        saveView21                       = 131,
        saveView22                       = 132,
        saveView23                       = 133,
        saveView24                       = 134,
        saveView25                       = 135,
        saveView26                       = 136,
        saveView27                       = 137,
        saveView28                       = 138,
        saveView29                       = 139,
        saveView30                       = 140,
        saveView31                       = 141,
        saveView32                       = 142,
        saveView33                       = 143,
        saveView34                       = 144,
        saveView35                       = 145,
        saveView36                       = 146,
        keyTab                           = 147,
        keySpace                         = 148,
        menu1                            = 149,
        menu2                            = 150,
        menu3                            = 151,
        menu4                            = 152,
        menu5                            = 153,
        menu6                            = 154,
        menu7                            = 155,
        menu8                            = 156,
        menu9                            = 157,
        menu10                           = 158,
        menu11                           = 159,
        menu12                           = 160,
        menu13                           = 161,
        menu14                           = 162,
        menu15                           = 163,
        menu16                           = 164,
        
        count                            = 165,
        noop                             = 0xFF,
    };

    struct button_iterator
    {
        button_type button;

        inline button_type operator*() const
        {
            return button;
        }

        inline button_iterator& operator++()
        {
            int button_id = static_cast<int>(button);
            button = static_cast<button_type>(button_id + 1);
            return *this;
        }

        inline button_iterator& operator--()
        {
            int button_id = static_cast<int>(button);
            button = static_cast<button_type>(button_id - 1);
            return *this;
        }

        inline bool operator==(const button_iterator& o) const
        {
            return button == o.button;
        }

        inline bool operator!=(const button_iterator& o) const
        {
            return button != o.button;
        }
    };

    struct all_buttons
    {
        inline button_iterator begin()
        {
            return { button_type::menuOptions };
        }

        inline button_iterator end()
        {
            return { button_type::count };
        }
    };

    enum class model_confidence
    {
        tested,
        testedViaFeedback,
        untestedShouldWork,
        unknown,
        unsupported
    };

    class reader_interface
    {

    };
}