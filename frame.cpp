#include "frame.h"
#include "editor_frame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxMDIParentFrame)
	EVT_MENU(wxID_NEW, MainFrame::OnMenuNew)
	EVT_MENU(wxID_OPEN, MainFrame::OnMenuOpen)
	EVT_MENU(wxID_SAVE, MainFrame::OnMenuSave)
	EVT_MENU(wxID_ABOUT, MainFrame::OnMenuAbout)
	EVT_MENU(wxID_EXIT, MainFrame::OnMenuExit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame()
	: wxMDIParentFrame(NULL, wxID_ANY, "Sprites Ahead")
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


	CreateStatusBar();
	SetStatusText("Welcome to Sprites Ahead!");
}

void MainFrame::OnMenuNew(wxCommandEvent& event)
{
	EditorFrame *f = new EditorFrame(this, "Test");
	f->Show();
	event.Skip();
}

void MainFrame::OnMenuOpen(wxCommandEvent& event)
{
}

void MainFrame::OnMenuSave(wxCommandEvent& event)
{
}

void MainFrame::OnMenuExit(wxCommandEvent& event)
{
	Close(true);
	event.Skip();
}

void MainFrame::OnMenuAbout(wxCommandEvent& event)
{
	wxMessageBox("If you have to ask, you're sprites behind",
			"About Sprites Ahead", wxOK | wxICON_INFORMATION);
	event.Skip();
}
