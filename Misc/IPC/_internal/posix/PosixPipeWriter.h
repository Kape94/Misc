#ifndef MISC_POSIX_PIPE_WRITER
#define MISC_POSIX_PIPE_WRITER

#include "Misc/Common/MiscNamespaceDefs.h"

#include <string>

BEGIN_MISC_NAMESPACE

class PosixPipeWriter {
    public:

        PosixPipeWriter(
            const std::string& _path
        );

        ~PosixPipeWriter();
        
        void Write(
            const std::string& message
        );

    private:

        const std::string path;
        int fdWrite = -1;
};

END_MISC_NAMESPACE

#endif
