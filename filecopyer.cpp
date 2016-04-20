#include "filecopyer.h"

void FileCopyer::run()
{
    if(mode == MODE_COPY)
    {
        Util::cpyLocal2Udisk();
        emit copyDone(MODE_COPY);
    }
    else if(mode == MODE_SCREENSHOT)
    {

        system(cmd.toStdString().c_str());
        usleep(500000);
        emit copyDone(MODE_SCREENSHOT);
    }
    else if(mode == MODE_UPDATE)
    {
        string dst("/home/program/temp/BoxUpdateFile");
        Util::cpyFile(filename.toStdString().c_str(),dst.c_str());
        Util::fileSync(dst.c_str());
        emit copyDone(MODE_UPDATE);
    }

}
