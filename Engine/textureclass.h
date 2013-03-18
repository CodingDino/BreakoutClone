// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// TextureClass
//		Holds one texture
#pragma once


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include <d3d11.h>
#include <d3dx11tex.h>


// |----------------------------------------------------------------------------|
// |						  Class: TextureClass								|
// |----------------------------------------------------------------------------|
class TextureClass
{
public:

	//|-------------------------------Public Functions--------------------------|

	// Constructors and Destructors
	TextureClass();
	TextureClass(const TextureClass&);
	~TextureClass();
    
    // Initialization and shutdown
	bool Initialize(ID3D11Device* device, WCHAR* filename);
	void Shutdown();

	// Getter functions
	ID3D11ShaderResourceView* GetTexture();

private:

	//|-----------------------------Private Data Members------------------------|

	// Texture
	ID3D11ShaderResourceView* m_texture;

};