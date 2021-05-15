#include "SA_view.h"

IMPLEMENT_DYNAMIC_CLASS(SAView, wxView)

BEGIN_EVENT_TABLE(SAView, wxView)
END_EVENT_TABLE()

SAView::SAView()
{
}

SAView::~SAView()
{
}

bool SAView::OnCreate(wxDocument *pDoc, long flags)
{
	return true;
}

void SAView::OnDraw(wxDC *pDC)
{
}

void SAView::OnUpdate(wxView *pSender, wxObject* pHint)
{
}

bool SAView::OnClose(bool deleteWindow)
{
	return true;
}
