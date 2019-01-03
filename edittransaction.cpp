#include "edittransaction.h"
#include "ui_edittransaction.h"
#include "account.h"
#include "databasereaderwriter.h"
#include "maindashboard.h"
#include <QPushButton>

editTransaction::editTransaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editTransaction)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Save Edit");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancel Edit");
    ui->transactionDateEdit->setDate(QDate::currentDate());
    setStyleSheet("QDialog {background: #a9e5aa}");
}

editTransaction::~editTransaction()
{
    delete ui;
}

QString editTransaction::transactionName() const
{
    return ui->transactionNameEdit->text();
}

QString editTransaction::transactionCategory() const
{
    return ui->transactionCategoryEdit->text();
}

QDate editTransaction::transactionDate() const
{
    return ui->transactionDateEdit->date();
}

double editTransaction::transactionAmount() const
{
    return ui->transactionAmountEdit->value();
}

void editTransaction::on_buttonBox_accepted()
{
    accept();
   // saveChangestoExpenditures(transactionCategory(), transactionName(), transactionDate(), transactionAmount());
}

void editTransaction::on_buttonBox_rejected()
{
    reject();
}

