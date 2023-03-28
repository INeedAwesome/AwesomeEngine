#include "pchawe.h"
#include "Application.h"

#include "Window/Window.h"

namespace Awe {

	Application::Application()
		: m_Width(1280), m_Height(720), m_RefreshRate(165)
	{
		this->SetRunning(1);

		// Init window
		m_Window = new Awe::Window(L"Want some extra juice!", m_Width, m_Height);

		// init graphics api
		ZeroMemory(&m_DXGISwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
		{
			m_DXGISwapChainDesc.BufferCount = 1;
			m_DXGISwapChainDesc.BufferDesc.Width = m_Width;
			m_DXGISwapChainDesc.BufferDesc.Height = m_Height;
			m_DXGISwapChainDesc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
			m_DXGISwapChainDesc.BufferDesc.RefreshRate.Numerator = m_RefreshRate;
			m_DXGISwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
			m_DXGISwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			m_DXGISwapChainDesc.OutputWindow = m_Window->GetHWND();
			m_DXGISwapChainDesc.SampleDesc.Count = 1;
			m_DXGISwapChainDesc.SampleDesc.Quality = 0;
			m_DXGISwapChainDesc.Windowed = 1;
		}

		m_FeatureLevel = D3D_FEATURE_LEVEL_11_0;

		CreateDXGIFactory1(__uuidof(IDXGIFactory), (void**) & m_IDXGIFactory);

		// todo here

		D3D11CreateDeviceAndSwapChain(
			NULL, 
			D3D_DRIVER_TYPE_REFERENCE, 
			NULL, 
			NULL, 
			&m_FeatureLevel, 
			1, 
			D3D11_SDK_VERSION, 
			&m_DXGISwapChainDesc, 
			&m_IDSGISwapChain,
			&m_ID3DDevice,
			&m_FeatureLevel, 
			&m_ID3DDeviceContext
		);
	

		// init some extra
	}

	Application::~Application()
	{
		delete m_Window;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			if (m_Window->ShouldClose())
			{
				std::cout << "Closing Window!" << std::endl;
				this->SetRunning(0);
			}

			Sleep(2);
		}
	}

	std::vector <IDXGIAdapter*> Application::EnumerateAdapters(void)
	{
		IDXGIAdapter* pAdapter;
		std::vector <IDXGIAdapter*> vAdapters;
		IDXGIFactory* pFactory = NULL;


		// Create a DXGIFactory object.
		if (FAILED(CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory)))
		{
			return vAdapters;
		}


		for (UINT i = 0;
			pFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND;
			++i)
		{
			vAdapters.push_back(pAdapter);
		}


		if (pFactory)
		{
			pFactory->Release();
		}

		return vAdapters;

	}
}