// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/11/7

#include <QString>
#include <QMap>
#include <QFileInfo>
#include "common/logger/inc/log.h"
#include "contrib/minizip/unzip.h"

#define THEME_FILE_NAME "default.theme.clr"

using namespace cc;

int main(int argc, char *argv[]) {
    QString path = QFileInfo(__FILE__).absolutePath() + "/../../../theme/" + THEME_FILE_NAME;
    auto *file = unzOpen(path.toStdString().c_str());
    if (file != nullptr) {
        unz_file_info unzFileInfo;

        char *fileName = new char[120];
        char *extField = new char[120];
        char *comment = new char[120];
        char *buf = new char[1024];

        auto *map = new QMap<QString, QByteArray *>();
        int len;
        QByteArray *byteArray;
        do {
            unzGetCurrentFileInfo(file, &unzFileInfo, fileName, 120, extField, 120, comment, 120);
            QString fName = QString(fileName);
            if (fName.endsWith("/")) {
                debug() << "目录：" << fName;
            } else {
                debug() << "文件：" << fName;
                if (unzOpenCurrentFile(file) == UNZ_OK) {
                    byteArray = new QByteArray();
                    while ((len = unzReadCurrentFile(file, buf, 1024)) > 0) {
                        byteArray->append(buf, len);
                    }
                    unzCloseCurrentFile(file);
                    (*map)[fName] = byteArray;
                } else {
                    debug() << "打开文件失败：" << fName;
                }
            }
        } while (unzGoToNextFile(file) == UNZ_OK);

        delete[] buf;
        delete[] comment;
        delete[] extField;
        delete[] fileName;

        unzClose(file);

        if (!map->isEmpty()) {
            QList<QString> keys = map->keys();
            for (const auto &key : keys) {
                debug() << "key:" << key;
                debug() << "内容：" << QString::fromUtf8(*(*map)[key]);
                delete (*map)[key];
            }
        }
        delete map;
    } else {
        debug() << "文件打开失败";
    }
    return 0;
}
