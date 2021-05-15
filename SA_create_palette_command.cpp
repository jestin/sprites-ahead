#include "SA_create_palette_command.h"

SACreatePaletteCommand::SACreatePaletteCommand(const wxString& name,
		CreatePaletteOperation op,
		SADocument* pDoc)
	: wxCommand(true, name)
{
}

SACreatePaletteCommand::~SACreatePaletteCommand()
{
}

bool SACreatePaletteCommand::Do()
{
	return true;
}

bool SACreatePaletteCommand::Undo()
{
	return true;
}
