#pragma once

#if ENABLE_S3

#include "ref.hh"

#include <optional>
#include <string>
#include <string_view>

namespace Aws { namespace Client { class ClientConfiguration; } }
namespace Aws { namespace S3 { class S3Client; } }

namespace nix {

struct S3Helper
{
    ref<Aws::Client::ClientConfiguration> config;
    ref<Aws::S3::S3Client> client;

    S3Helper(const std::string & profile, const std::string & region, const std::string & scheme, const std::string & endpoint);

    ref<Aws::Client::ClientConfiguration> makeConfig(const std::string & region, const std::string & scheme, const std::string & endpoint);

    struct FileTransferResult
    {
        std::optional<std::string> data;
        unsigned int durationMs;
    };

    FileTransferResult getObject(std::string_view bucketName, std::string_view key);
};

}

#endif
