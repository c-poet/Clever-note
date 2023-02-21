// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/10/26

#include "inc/mainwindow.h"
#include <QToolBar>
#include <QTextEdit>
#include <QListWidget>
#include "common/core/inc/core.h"

cd::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setWindowTitle("Clever Note");
    this->setMinimumWidth(800);
    this->setMinimumHeight(480);
    QTextEdit *edit = new QTextEdit(this);
    this->setCentralWidget(edit);


    QTextDocument *doc = edit->document();
    connect(doc, &QTextDocument::blockCountChanged, [](int count) {
        qInfo() << "blockCountChanged:" << count;
    });
    connect(doc, &QTextDocument::contentsChange, [](int form, int remove, int add) {
        qInfo() << "contentsChange:" << form << "|" << remove << "|" << add;
    });
    connect(doc, &QTextDocument::modificationChanged, [](bool status) {
        qInfo() << "modificationChanged:" << status;
    });
    connect(doc, &QTextDocument::cursorPositionChanged, [](const QTextCursor &cursor) {
        qInfo() << "cursorPositionChanged:" << cursor.position();
    });
    connect(edit, &QTextEdit::cursorPositionChanged, [=] () {
        qInfo() << "当前位置：" << edit->textCursor().position();
    });
}

cd::MainWindow::~MainWindow() = default;
