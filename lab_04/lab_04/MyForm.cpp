#include "MyForm.h"

namespace lab_04
{
    System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
    {
        lift = gcnew cLiftSys();

        lift->b0->linkTo(btn0);
        lift->b1->linkTo(btn1);
        lift->b2->linkTo(btn2);
        lift->b3->linkTo(btn3);

        lift->c->linkTo(lblInfoController);
        lift->l->linkTo(lblInfoLift);
        lift->l->linkTim(tLiftMove);
        lift->d->linkTo(lblInfoDoor);
        lift->d->linkTimers(tDoorWork, tDoorOpen);
    }

    System::Void MyForm::btn0_Click(System::Object^  sender, System::EventArgs^  e)
    {
        lift->b0->onClick();
    }

    System::Void MyForm::btn1_Click(System::Object^  sender, System::EventArgs^  e)
    {
        lift->b1->onClick();
    }

    System::Void MyForm::btn2_Click(System::Object^  sender, System::EventArgs^  e)
    {
        lift->b2->onClick();
    }

    System::Void MyForm::btn3_Click(System::Object^  sender, System::EventArgs^  e)
    {
        lift->b3->onClick();
    }

    System::Void MyForm::tClock_Tick(System::Object^  sender, System::EventArgs^  e)
    {
		//
		// Таймер
		//
        static int clock = 0;

        switch (clock)
        {
        case 0:
            lblClock->Text = "[-]";
            break;
        case 1:
            lblClock->Text = "[\\]";
            break;
        case 2:
            lblClock->Text = "[|]";
            break;
        case 3:
            lblClock->Text = "[/]";
            break;
        }
        clock = (clock + 1) % 4;
    }
}
