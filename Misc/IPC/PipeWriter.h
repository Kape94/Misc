#ifndef MISC_PIPE_WRITER
#define MISC_PIPE_WRITER

#include "Misc/Common/MiscNamespaceDefs.h"

#include "_internal/posix/PosixPipeWriter.h"

#include <string>

BEGIN_MISC_NAMESPACE

class PipeWriter {
    public:

        PipeWriter(
            const std::string& path
        );

        ~PipeWriter();

        void Write(
            const std::string& message
        );

    private:

        Misc::PosixPipeWriter pipe;
};

END_MISC_NAMESPACE

#endif
