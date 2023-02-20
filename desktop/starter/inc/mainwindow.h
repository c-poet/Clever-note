// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/10/26

#ifndef _CD_STARTER_MAIN_WINDOW_H
#define _CD_STARTER_MAIN_WINDOW_H

#include <QMainWindow>
#include "desktop/richtext/inc/richtext.h"

class MainWindow : public QMainWindow {
Q_OBJECT

private:
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;
};

#endif
