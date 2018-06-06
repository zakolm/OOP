#include "MyForm.h"

using namespace lab_03;

[STAThreadAttribute]

int main(array<System::String^>^ argv)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());
    return 0;
}
