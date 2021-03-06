#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include "clientmodel.h"
#include "version.h"

// Copyright year (2009-this)
// Todo update this when changing our copyrights comments in the source
const int ABOUTDIALOG_COPYRIGHT_YEAR = 2014;

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    
    // Set current copryright year
    ui->copyrightLabel->setText(tr("Copyright") + QString(" &copy; 2009-%1 ") + tr("The Bitcoin developers") + QString("<br>") + tr("Copyright") + QString(" &copy; ") + tr("2011-%1 The Litecoin developers") + QString("<br>") + tr("Copyright") +QString(" &copy; ") + tr("%1 TOKEN Developer").arg(2020));
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
