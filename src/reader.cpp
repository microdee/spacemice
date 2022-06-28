#include "reader.h"

#include "hidapi.h"

namespace spacemice
{
    reader::reader()
    {
        hid_init();
    }

    reader::~reader()
    {
        hid_exit();
    }
}