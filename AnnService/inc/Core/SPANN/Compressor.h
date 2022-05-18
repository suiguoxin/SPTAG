// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _SPTAG_SPANN_COMPRESSOR_H_
#define _SPTAG_SPANN_COMPRESSOR_H_

#include <string>
#include "zstd.h"
#include "../Common.h"

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
            
            std::string Compress(const std::string &src)
            {
                size_t est_compress_size = ZSTD_compressBound(src.size());

                std::string buffer{};
                buffer.resize(est_compress_size);
                size_t compressed_size = ZSTD_compress((void*)buffer.data(), est_compress_size,
                    src.data(), src.size(), 1);

                buffer.resize(compressed_size);
                buffer.shrink_to_fit();

                return buffer;
            }

            // return the compressed sie
            size_t GetCompressedSize(const std::string &src)
            {
                std::string dst = Compress(src);
                return dst.size();
            }

        private:
            int compress_level;
            //std::string buffer{};
            std::string dictionary{};
        };
    } // SPANN
} // SPTAG

#endif // _SPTAG_SPANN_COMPRESSOR_H_
