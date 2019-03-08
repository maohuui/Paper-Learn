
#include "stdafx.h"
#include "PrintController.h"
#include "PrintModel.h"
#include "PrintView.h"
#include <iostream>
 
using std::wcin;
using std::endl;
 
int _tmain(int argc, _TCHAR* argv[])
{
 
	
	PrintModel model;
	PrintController controller(&model);
	PrintView view(&model);
	controller.Register(&model,&view);
 
	view.Run();
	std::wstring str;
 
	while (1)
	{
		wcin>>str;
		controller.HandleUserInput(&str);
	}
 
	return 0;
}
