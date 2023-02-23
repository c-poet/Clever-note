// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/10/26

#include <QToolBar>
#include <QTextEdit>
#include <QListWidget>
#include "inc/mainwindow.h"
#include "common/logger/inc/log.h"

using namespace cc;

cd::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setWindowTitle("Clever Note");
    this->setMinimumWidth(800);
    this->setMinimumHeight(480);
    QTextEdit *edit = new QTextEdit(this);
    this->setCentralWidget(edit);


    QTextDocument *doc = edit->document();
    connect(doc, &QTextDocument::blockCountChanged, [](int count) {
        Log::info() << "blockCountChanged:" << count;
    });
    connect(doc, &QTextDocument::contentsChange, [](int form, int remove, int add) {
        Log::info() << "contentsChange:" << form << "|" << remove << "|" << add;
    });
    connect(doc, &QTextDocument::modificationChanged, [](bool status) {
        Log::info() << "modificationChanged:" << status;
    });
    connect(doc, &QTextDocument::cursorPositionChanged, [](const QTextCursor &cursor) {
        Log::info() << "cursorPositionChanged:" << cursor.position();
    });
    connect(edit, &QTextEdit::cursorPositionChanged, [=]() {
        Log::info() << "当前位置：" << edit->textCursor().position();
    });
}

cd::MainWindow::~MainWindow() = default;
