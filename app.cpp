#include "app.h"
#include "frame.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	Main * frame = new Main();
	frame->Show(true);
	return true;
}
