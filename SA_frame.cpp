#include "SA_frame.h"
#include "editor_frame.h"
#include "SA_palette_frame.h"

#define ID_NEW_PALETTE 20001

wxBEGIN_EVENT_TABLE(SAFrame, wxMDIParentFrame)
	EVT_MENU(wxID_NEW, SAFrame::OnMenuNewSprite)
	EVT_MENU(ID_NEW_PALETTE, SAFrame::OnMenuNewPalette)
	EVT_MENU(wxID_OPEN, SAFrame::OnMenuOpen)
	EVT_MENU(wxID_SAVE, SAFrame::OnMenuSave)
	EVT_MENU(wxID_ABOUT, SAFrame::OnMenuAbout)
	EVT_MENU(wxID_EXIT, SAFrame::OnMenuExit)
wxEND_EVENT_TABLE()

SAFrame::SAFrame()
	: wxMDIParentFrame(NULL, wxID_ANY, "Sprites Ahead")
{
	// create menus
	wxMenuBar *menuBar = new wxMenuBar;
	SetMenuBar(menuBar);

	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_NEW, "&New Sprite");
	menuFile->Append(ID_NEW_PALETTE, "New &Palette\tCtrl+P");
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

void SAFrame::OnMenuNewSprite(wxCommandEvent& event)
{
	EditorFrame *f = new EditorFrame(this, "Test");
	f->Show();
	event.Skip();
}

void SAFrame::OnMenuNewPalette(wxCommandEvent& event)
{
	SAPaletteFrame *f = new SAPaletteFrame(this, "Test");
	f->Show();
	event.Skip();
}

void SAFrame::OnMenuOpen(wxCommandEvent& event)
{
}

void SAFrame::OnMenuSave(wxCommandEvent& event)
{
}

void SAFrame::OnMenuExit(wxCommandEvent& event)
{
	Close(true);
	event.Skip();
}

void SAFrame::OnMenuAbout(wxCommandEvent& event)
{
	wxMessageBox("If you have to ask, you're sprites behind",
			"About Sprites Ahead", wxOK | wxICON_INFORMATION);
	event.Skip();
}
