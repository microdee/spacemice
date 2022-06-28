#pragma once

#include "spacemice.h"

#include <unordered_map>
#include <functional>
#include <memory>
#include <vector>

namespace spacemice
{
    namespace devices
    {
        class device;
        struct device_instantiation;

        struct vid_pid
        {
            uint16_t vid;
            uint16_t pid;
        };

        typedef uint32_t vid_pid_pair;
        typedef std::function<std::shared_ptr<device>(const device_instantiation&)> device_creator;

        class factory
        {
        public:
            factory();
            ~factory();

        private:
            std::unordered_map<vid_pid_pair, device_creator> knwon_models;
            void add_model(const vid_pid& id, device_creator creator);
            std::vector<device> open_connected();
        };
    }
}