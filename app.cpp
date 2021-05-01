#include "app.h"
#include "frame.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MainFrame * frame = new MainFrame();
	frame->Show(true);
	return true;
}
