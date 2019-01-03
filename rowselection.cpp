#include "rowselection.h"
#include "ui_rowselection.h"
#include "edittransaction.h"
#include <QPushButton>

rowSelection::rowSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rowSelection)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Edit Row");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancel");
    setStyleSheet("QDialog {background: #a9e5aa}");
}

rowSelection::~rowSelection()
{
    delete ui;
}

int rowSelection::editRowNumber()
{
    return ui -> editRowNum -> value();
}


void rowSelection::on_buttonBox_accepted()
{

}
