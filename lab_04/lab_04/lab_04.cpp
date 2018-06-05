#include "MyForm.h"

using namespace lab_04;

[STAThreadAttribute]

int main(array<System::String^>^ argv)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());
    return 0;
}
