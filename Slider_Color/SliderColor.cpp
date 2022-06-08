#include "SliderColor.h" 

CSliderControlDlg* CSliderControlDlg::ptr = NULL;

int i1 = 0;
int i2 = 0;
int i3 = 0;

CSliderControlDlg::CSliderControlDlg(void)
{
	ptr = this;
}

void CSliderControlDlg::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL CSliderControlDlg::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hDialog = hwnd;
	hHorizontalSlider[0] = GetDlgItem(hDialog, IDC_SLIDER1);
	hHorizontalSlider[1] = GetDlgItem(hDialog, IDC_SLIDER2);
    hHorizontalSlider[2] = GetDlgItem(hDialog, IDC_SLIDER3); 
    hButton = GetDlgItem(hDialog, IDC_PROGRESS1);

	SendMessage(hButton, PBM_SETBKCOLOR, 0, LPARAM(RGB(0, 0, 0))); // Установка цвета фона индикатора
	SendMessage(hHorizontalSlider[0], TBM_SETRANGE, TRUE, MAKELPARAM(MIN, MAX));
	SendMessage(hHorizontalSlider[1], TBM_SETRANGE, TRUE, MAKELPARAM(MIN, MAX));
	SendMessage(hHorizontalSlider[2], TBM_SETRANGE, TRUE, MAKELPARAM(MIN, MAX));
	return TRUE;
}

void CSliderControlDlg::Cls_OnHScroll(HWND hwnd, HWND hwndCtl, UINT code, int pos)
{ 
	if (hwndCtl == hHorizontalSlider[0])
	{
		static int nOldPosition = 0;
		int nCurrrentPosition = SendMessage(hwndCtl, TBM_GETPOS, 0, 0);
		switch (code)
		{
		case TB_THUMBTRACK:
			i1 += nCurrrentPosition - nOldPosition;
			break;
		}
		nOldPosition = nCurrrentPosition;
		SendMessage(hButton, PBM_SETBKCOLOR, 0, LPARAM(RGB(i1, i2, i3))); // Установка цвета фона индикатора 
	}

	else if (hwndCtl == hHorizontalSlider[1])
	{
		static int nOldPosition = 0;
		int nCurrrentPosition = SendMessage(hwndCtl, TBM_GETPOS, 0, 0);
		switch (code)
		{
		case TB_THUMBTRACK:
			i2 += nCurrrentPosition - nOldPosition;
			break;
		}
		nOldPosition = nCurrrentPosition;
		SendMessage(hButton, PBM_SETBKCOLOR, 0, LPARAM(RGB(i1, i2, i3))); // Установка цвета фона индикатора 
	}

	else if (hwndCtl == hHorizontalSlider[2])
	{
		static int nOldPosition = 0;
		int nCurrrentPosition = SendMessage(hwndCtl, TBM_GETPOS, 0, 0);
		switch (code)
		{
		case TB_THUMBTRACK:
			i3 += nCurrrentPosition - nOldPosition;
			break;
		}
		nOldPosition = nCurrrentPosition;
		SendMessage(hButton, PBM_SETBKCOLOR, 0, LPARAM(RGB(i1, i2, i3))); // Установка цвета фона индикатора 
	}
	 


}  

BOOL CALLBACK CSliderControlDlg::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_HSCROLL, ptr->Cls_OnHScroll);  
	}
	return FALSE;
}