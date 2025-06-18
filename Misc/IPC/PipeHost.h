#ifndef MISC_PIPE_HOST
#define MISC_PIPE_HOST

#include "Misc/Common/MiscNamespaceDefs.h"

#include "_internal/posix/PosixPipeHost.h"

#include <string>

BEGIN_MISC_NAMESPACE

class PipeHost {
    public:

        PipeHost(
            const std::string& path
        );

        ~PipeHost();

        std::string Read();

    private:

        Misc::PosixPipeHost pipe;
};

END_MISC_NAMESPACE

#endif
