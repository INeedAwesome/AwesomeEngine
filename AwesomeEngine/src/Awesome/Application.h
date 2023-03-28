#pragma once

#include "Window/Window.h"

#include <d3d11.h>

namespace Awe {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void SetRunning(int32_t run) { m_Running = run; }

		std::vector <IDXGIAdapter*> EnumerateAdapters(void);


	private:
		Awe::Window* m_Window;
		int32_t m_Running;

		uint32_t m_Width;
		uint32_t m_Height;
		uint32_t m_RefreshRate;

		DXGI_SWAP_CHAIN_DESC m_DXGISwapChainDesc;
		D3D_FEATURE_LEVEL m_FeatureLevel;

		IDXGIFactory1* m_IDXGIFactory;
		IDXGIAdapter1* m_IDXGIAdapter;
		IDXGIOutput* m_IDXGIOutput;


		IDXGISwapChain* m_IDSGISwapChain;
		ID3D11Device* m_ID3DDevice;
		ID3D11DeviceContext* m_ID3DDeviceContext;

	};

	// define in client
	Application* CreateApplication();
}
