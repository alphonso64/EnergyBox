#include "filecopyer.h"

void FileCopyer::run()
{
    Util::cpyLocal2Udisk();
    emit copyDone();
}
