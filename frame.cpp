#include "frame.h"
#include "editor_frame.h"

wxBEGIN_EVENT_TABLE(Main, wxMDIParentFrame)
	EVT_MENU(wxID_NEW, Main::OnMenuNew)
	EVT_MENU(wxID_OPEN, Main::OnMenuOpen)
	EVT_MENU(wxID_SAVE, Main::OnMenuSave)
	EVT_MENU(wxID_ABOUT, Main::OnMenuAbout)
	EVT_MENU(wxID_EXIT, Main::OnMenuExit)
wxEND_EVENT_TABLE()

Main::Main()
	: wxMDIParentFrame(NULL, wxID_ANY, "Sprite Editor")
{
	// create menus
	wxMenuBar *menuBar = new wxMenuBar;
	SetMenuBar(menuBar);

	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_NEW, "&New");
	menuFile->Append(wxID_OPEN, "&Open");
	menuFile->Append(wxID_SAVE, "&Save");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	// create palette
	wxToolBar *toolBar = CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	wxColor palette[16];
	palette[0] =  wxColor(0, 0, 0);
	palette[1] =  wxColor(0, 0, 128);
	palette[2] =  wxColor(0, 128, 0);
	palette[3] =  wxColor(0, 128, 128);
	palette[4] =  wxColor(128, 0, 0);
	palette[5] =  wxColor(128, 0, 128);
	palette[6] =  wxColor(128, 128, 0);
	palette[7] =  wxColor(192, 192, 192);
	palette[8] =  wxColor(128, 128, 128);
	palette[9] =  wxColor(0, 0, 255);
	palette[10] =  wxColor(0, 255, 0);
	palette[11] =  wxColor(0, 255, 255);
	palette[12] =  wxColor(255, 0, 0);
	palette[13] =  wxColor(255, 0, 255);
	palette[14] =  wxColor(255, 255, 0);
	palette[15] =  wxColor(255, 255, 255);

	for(int i = 0; i < 16; i++)
	{
		wxButton *b = new wxButton(
				toolBar, 
				10100 + i, 
				"", 
				wxDefaultPosition, 
				wxSize(40,20), 
				0);
		b->SetBackgroundColour(palette[i]);
		b->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Main::OnSelectColor), NULL);
		toolBar->AddControl(b);
	}

	wxButton *b = new wxButton(
			toolBar, 
			10100 + 16, 
			"ALPHA", 
			wxDefaultPosition, 
			wxSize(40,20), 
			0);
	b->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Main::OnSelectColor), NULL);
	toolBar->AddControl(b);

	toolBar->Realize();

	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
}

void Main::OnMenuNew(wxCommandEvent& event)
{
	EditorFrame *f = new EditorFrame(this, "Test");
	f->Show();
	event.Skip();
}

void Main::OnMenuOpen(wxCommandEvent& event)
{
}

void Main::OnMenuSave(wxCommandEvent& event)
{
}

void Main::OnMenuExit(wxCommandEvent& event)
{
	Close(true);
	event.Skip();
}

void Main::OnMenuAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets Sprite Editor example",
			"About Sprite Editor", wxOK | wxICON_INFORMATION);
	event.Skip();
}

void Main::OnSelectColor(wxCommandEvent &evvent)
{
}

