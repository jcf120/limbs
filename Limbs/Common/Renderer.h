#pragma once

class Renderer
{
public:
	Renderer(void);
	~Renderer(void);

	void Render();

private:
	void SetupViewport();
};

