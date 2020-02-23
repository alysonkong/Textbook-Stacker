#include "nameinputwindow.h"

nameinputwindow::nameinputwindow(QWidget *parent) : QWidget(parent)
{
    nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("Name...");
    nameEdit->setFocus();
    nameEdit->setMaxLength(10);

    connect(nameEdit, SIGNAL(editingFinished()),
                this, SLOT(namechanged()));


}

void nameinputwindow::namechanged(){
   emit playername(nameEdit->text());

}
