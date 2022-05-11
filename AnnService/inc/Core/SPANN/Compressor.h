// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _SPTAG_SPANN_COMPRESSOR_H_
#define _SPTAG_SPANN_COMPRESSOR_H_

#include <string>
// #include "zstd.h"

namespace SPTAG {
    namespace SPANN {
        class Compressor
        {
        public:
            Compressor()
            {
                compress_level = 1;
            }

            virtual ~Compressor(){}

            // return the compressed sie
            size_t Compress(const void* src, void* dst) 
            {
                //size_t est_compress_size = ZSTD_compressBound(data.size());
                //buffer.resize(est_compress_size);

                //auto compress_size = ZSTD_compress((void*)buffer.data(), est_compress_size,
                //    data.data(), data.size(), compress_level);

                //buffer.resize(compress_size);
                //buffer.shrink_to_fit();
                //return compress_size;
                return 100;
            }

            size_t GetCompressedSize(const void * src, size_t srcSize)
            {
                return 100;
            }

        private:
            int compress_level;
            std::string buffer{};
            std::string dictionary{};
        };

    } // SPANN
} // SPTAG

#endif // _SPTAG_SPANN_COMPRESSOR_H_
