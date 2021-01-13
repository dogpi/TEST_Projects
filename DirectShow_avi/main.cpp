#include <dshow.h>
#include <iostream>

using namespace std;



void main(void)
{
	IGraphBuilder *pGraph = NULL;
	IMediaControl *pControl = NULL;
	IMediaEvent   *pEvent = NULL;

	// 初始化COM库
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr)){
		cout << "ERROR - Cluld not initialize COM library" << endl;
		return;
	}

	// 创建filter graph管理器
	hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraph);
	if (FAILED(hr)){
		cout << "ERROR - Cluld not create the Filter Manager" << endl;
		return;
	}

	hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
	hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);

	hr = pGraph->RenderFile(L"E:\\GitHub\\TEST_Projects\\DirectShow_avi\\Example.avi", NULL);

	if (SUCCEEDED(hr)){
		hr = pControl->Run();
		if (SUCCEEDED(hr)){
			long evCode;
			pEvent->WaitForCompletion(INFINITE, &evCode);
		}
	}
	pControl->Release();
	pEvent->Release();
	pGraph->Release();
	CoUninitialize();


}