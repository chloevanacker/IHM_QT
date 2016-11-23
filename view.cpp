#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View)
{
    ui->setupUi(this);

    main_area = new QMdiArea ;

    /*Set the scrolling to only if needed*/
    main_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    main_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    /*Set the main widget to be the main area*/
    setCentralWidget(main_area);
    setWindowTitle("Montage");

    create_actions();
    create_menu();
    create_tool_bar();

    open_action_image->setEnabled(true);
    open_action_video->setEnabled(true);

    assemble_action->setEnabled(false);
    convert_action->setEnabled(false);
    save_action->setEnabled(false);
    save_as_action->setEnabled(false);



    this->message_box = new QMessageBox;
}

View::~View()
{
    delete ui;

    delete main_area;
    delete controller;

    this->delete_actions();
    this->delete_menus();
    this->delete_tool_bars();
}

void View::delete_actions()
{
    delete open_action_image;
    delete open_action_video;
    delete save_action;
    delete save_as_action;
    delete convert_action;
    delete assemble_action;
    delete help_action;
    delete about_action;
}

void View::delete_menus()
{
    delete file_menu;
    delete action_menu;
    delete help_menu;
    delete about_menu;
}

void View::delete_tool_bars()
{
    delete file_tool_bar;
    delete modification_tool_bar;

}


void View::create_menu()
{
    file_menu = menuBar()->addMenu(tr("&File"));
    file_menu->addAction(open_action_image);
    file_menu->addAction(open_action_video);
    file_menu->addAction(save_action);
    file_menu->addAction(save_as_action);

    action_menu = menuBar()->addMenu(tr("&Action"));
    action_menu->addAction(convert_action);
    action_menu->addAction(assemble_action);

    help_menu = menuBar()->addMenu(tr("&Help"));
    help_menu->addAction(help_action);

    about_menu = menuBar()->addMenu(tr("&About"));
    about_menu->addAction(about_action);
}

void View::create_tool_bar()
{
    file_tool_bar = addToolBar(tr("&File"));
    file_tool_bar->addAction(open_action_image);
    file_tool_bar->addAction(open_action_video);
    file_tool_bar->addAction(save_action);
    file_tool_bar->addAction(save_as_action);

    modification_tool_bar = addToolBar(tr("&Modification"));
    modification_tool_bar->addAction(convert_action);
    modification_tool_bar->addAction(assemble_action);

}

void View::create_actions()
{
    open_action_image = new QAction(QIcon("://icons/openimage.png"), tr("Open..."), this);
    open_action_image->setStatusTip(tr("Open new picture files"));
    connect(open_action_image, SIGNAL(triggered()), this, SLOT(open_image()));

    open_action_video = new QAction(QIcon("://icons/openvideo.png"), tr("Open..."), this);
    open_action_video->setStatusTip(tr("Open new video files"));
    connect(open_action_video, SIGNAL(triggered()), this, SLOT(open_video()));

    save_action = new QAction(QIcon("://icons/save.png"), tr("Save"), this);
    save_action->setStatusTip(tr("Save the file"));
    connect(save_action, SIGNAL(triggered()), this, SLOT(save()));

    save_as_action = new QAction(QIcon("://icons/save_as.png"), tr("Save As..."), this);
    save_as_action->setStatusTip(tr("Save the file as a new document"));
    connect(save_as_action, SIGNAL(triggered()), this, SLOT(save_as()));

    convert_action = new QAction(QIcon("://icons/black_and_white.png"), tr("Black and White"), this);
    convert_action->setStatusTip(tr("Converts all pictures or videos to black and white"));
    connect(convert_action, SIGNAL(triggered()), this, SLOT(convert_all()));

    assemble_action = new QAction(QIcon("://icons/assemble.png"), tr("Assemble"), this);
    assemble_action->setStatusTip(tr("Assemble all the open pictures or videos into one"));
    connect(assemble_action, SIGNAL(triggered()), this, SLOT(assemble()));

    help_action = new QAction(QIcon(":/icons/help.png"), tr("Help..."), this);
    help_action->setStatusTip(tr("Open help"));
    connect(help_action, SIGNAL(triggered()), this, SLOT(help()));

    about_action = new QAction(QIcon(":/icons/about.png"), tr("About..."), this);
    about_action->setStatusTip(tr("About this application"));
    connect(about_action, SIGNAL(triggered()), this, SLOT(about()));


}

void View::initial_actions_state()
{
    open_action_image->setEnabled(true);
    open_action_video->setEnabled(true);

    assemble_action->setEnabled(false);
    convert_action->setEnabled(false);
    save_action->setEnabled(false);
    save_as_action->setEnabled(false);
}

void View::open_image()
{
    this->controller->open_image();
    open_action_video->setEnabled(false);
}

void View::open_video()
{
    this->controller->open_video();
    open_action_image->setEnabled(false);
}


void View::save()
{
    this->controller->save();
    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    msg.setText("L'image est sauvergardée.");
    msg.exec();
}

void View::save_as()
{
    this->controller->save_as();
}

void View::convert_all()
{
    this->controller->convert_all();
    save_action->setEnabled(true);
    save_as_action->setEnabled(true);
}

void View::assemble()
{
    this->controller->assemble();
    assemble_action->setEnabled(false);
    save_action->setEnabled(true);
    save_as_action->setEnabled(true);

}


void View::help()
{
    this->controller->help();
}

void View::about()
{
    this->controller->about();
}


void View::display_message_box(QString title, QString content)
{
    this->message_box->setWindowTitle(title);
    this->message_box->setText(content);
    this->message_box->setIcon(QMessageBox::Information);
    this->message_box->show();
}

QStringList View::display_open_box_image()
{
    QFileDialog* file_dialog = new QFileDialog;
    file_dialog->setFileMode(QFileDialog::ExistingFiles);
    QStringList file_names = file_dialog->getOpenFileNames(this, tr("Open one or more files"), NULL, tr("IMAGES (*.png *.jpg *.jpeg)"));
    delete (file_dialog);

    assemble_action->setEnabled(true);
    convert_action->setEnabled(true);

    return file_names;
}

QStringList View::display_open_box_video()
{
    QFileDialog* file_dialog = new QFileDialog;
    file_dialog->setFileMode(QFileDialog::ExistingFiles);
    QStringList file_names = file_dialog->getOpenFileNames(this, tr("Open one or more files"), NULL, tr("VIDEOS (*.avi *.mp4)"));
    delete (file_dialog);

    assemble_action->setEnabled(true);
    convert_action->setEnabled(true);

     return file_names;
}


QString View::display_save_as_box()
{
    QFileDialog* file_dialog = new QFileDialog;
    file_dialog->setFileMode(QFileDialog::ExistingFiles);
    file_dialog->setAcceptMode(QFileDialog::AcceptSave);
    QString file_name = file_dialog->getSaveFileName(this, "Save File", NULL, "IMAGES (*.png *.jpg *.jpeg);; VIDEOS (*.avi)");
    delete (file_dialog);
    return file_name;
}

void View::add_sub_window()
{
    MySubWindows* new_sub_window = new MySubWindows(this, this->controller);
//    new_sub_window->installEventFilter(close_sub);
    this->main_area->addSubWindow(new_sub_window);
    sub_windows.push_back(new_sub_window);
}

void View::display_sub_window(int index_of_sub_window)
{
    this->sub_windows[index_of_sub_window]->show();
    this->sub_windows[index_of_sub_window]->adjustSize();
}


void View::hide_sub_window(int index_of_sub_window)
{
    this->sub_windows[index_of_sub_window]->hide();
}

void View::refresh_sub_window(int index_of_sub_window)
{
    QLabel* result_label = new QLabel;
    *(this->controller->pixmaps[index_of_sub_window]) = QPixmap::fromImage(this->controller->vector_threads_images[index_of_sub_window]->result);
    result_label->setPixmap(*this->controller->pixmaps[index_of_sub_window]);
    this->sub_windows[index_of_sub_window]->setWidget(result_label);
    this->display_sub_window(index_of_sub_window);

}
