#pragma once

#include <wx/wx.h>

class wxCanvasEvent : public wxNotifyEvent
{
	public:
	wxCanvasEvent(wxEventType commandType = wxEVT_NULL,
			int id = 0) : wxNotifyEvent(commandType, id) {}

	wxCanvasEvent(const wxCanvasEvent& event) : wxNotifyEvent(event) {}

	virtual wxEvent* Clone() const
	{
		return new wxCanvasEvent(*this);
	}

	DECLARE_DYNAMIC_CLASS(wxCanvasEvent);

	public:

	int zoom;
};

typedef void (wxEvtHandler::*wxCanvasEventFunction) (wxCanvasEvent&);

BEGIN_DECLARE_EVENT_TYPES()
	DECLARE_EVENT_TYPE(wxEVT_CANVAS_ZOOM_CHANGED, 801)
	DECLARE_EVENT_TYPE(wxEVT_CANVAS_ZOOM_IN, 802)
	DECLARE_EVENT_TYPE(wxEVT_CANVAS_ZOOM_OUT, 803)
END_DECLARE_EVENT_TYPES()

#define EVT_CANVAS_ZOOM_CHANGED(id, fn) DECLARE_EVENT_TABLE_ENTRY( \
		wxEVT_CANVAS_ZOOM_CHANGED, id, -1, (wxObjectEventFunction) \
		(wxEventFunction) (wxCanvasEventFunction) & fn, \
		(wxObject *) NULL ),

#define EVT_CANVAS_ZOOM_IN(id, fn) DECLARE_EVENT_TABLE_ENTRY( \
		wxEVT_CANVAS_ZOOM_IN, id, -1, (wxObjectEventFunction) \
		(wxEventFunction) (wxCanvasEventFunction) & fn, \
		(wxObject *) NULL ),

#define EVT_CANVAS_ZOOM_OUT(id, fn) DECLARE_EVENT_TABLE_ENTRY( \
		wxEVT_CANVAS_ZOOM_OUT, id, -1, (wxObjectEventFunction) \
		(wxEventFunction) (wxCanvasEventFunction) & fn, \
		(wxObject *) NULL ),
