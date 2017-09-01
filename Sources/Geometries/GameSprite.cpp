#include "GameSprite.h"

GameSprite::GameSprite(float framesPerSecond, float animationSpeed, bool isLooping) : GameBitmap()
{
	FramePerSecond = 1 / framesPerSecond;
	AnimationSpeed = animationSpeed;
	IsLooping = isLooping;
	CurrentSpeed = 0;
	CurrentMotion = 0;
}

GameSprite::~GameSprite()
{
}

void GameSprite::Initialize(ID3D10Device *device, wchar_t *filePath, int bitmapWidth, int bitmapHeight, float numberOfMotions)
{
	CurrentFrame = 0;
	PreviousFrame = -1.0f;
	MaxFrames = (float)bitmapWidth / (float)(bitmapHeight / numberOfMotions);
	NumOfMotions = numberOfMotions;

	FrameWidth = bitmapWidth / MaxFrames;
	FrameHeight = bitmapHeight / NumOfMotions;

	GameBitmap::Initialize(device, filePath, bitmapWidth / MaxFrames, bitmapHeight / numberOfMotions);
}

void GameSprite::Update(float dt)
{
	if (MaxFrames == 1.0f) return;

	/*
		���濡 üũ�� ���� ������
		IsLooping ���� �ʱ⿡ false ������ ������ �� ���Ƶ�
		������ �����ӱ��� ������Ʈ �ǰ� ������ �Ǳ� ������
		�ش� ��ġ�� �߰��ϰԵ�
	*/
	if (!IsLooping)
	{
		CurrentFrame = MaxFrames;
		return;
	}

	if (CurrentFrame <= MaxFrames) {
		CurrentSpeed += AnimationSpeed * dt;

		if (CurrentSpeed > FramePerSecond) {
			CurrentFrame++;
			CurrentSpeed = 0;

			if (CurrentFrame >= MaxFrames) {
				if (IsLooping) {
					CurrentFrame = 0;
				}
				//�ʱ� üũ ��ġ
				//else {
				//	CurrentFrame = MaxFrames;
				//}
			}
		}
	}
}

/*
	��������Ʈ�� ��ġ �� �ִϸ��̼�(������)�� ������ ������Ʈ�ϰ�, �����Ѵ�.
	��, ���� �� �۾��� ��������� �ټ� ��ȿ�����̴�.
		1. ���� ���� �۾��� 2�� �����Ѵ�. �� ������Ʈ����~!
		2. �׿� ���� ���� �۾��� 2�� �����Ѵ�.
	���Ŀ� �� ���� �����ؾߵ� �� �ʹ�.
*/
void GameSprite::Render(ID3D10Device * device, int screenWidth, int screenHeight, float posX, float posY)
{
	// ��ġ ������ ������Ʈ�ϰ�, �����Ѵ�.
	GameBitmap::Render(device, screenWidth, screenHeight, posX, posY);
	// ��������Ʈ�� �ִϸ��̼�(������)�� ������Ʈ�Ѵ�.
	UpdateBuffers(device);

	/*
		�̰� ���� ���Ѱ��� �Ѥ�
	*/
	// �����Ѵ�.
	//unsigned int stride = sizeof(VertexType);
	//unsigned int offset = 0;

	//device->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
	//device->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	//device->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

void GameSprite::SetMotion(float index)
{
	if (CurrentMotion != index)
	{
		CurrentMotion = index;
	}
}

void GameSprite::SetLooping(bool condition)
{
	if (IsLooping != condition)
	{
		IsLooping = condition;
	}
}

float GameSprite::GetMaxFrame() const
{
	return MaxFrames;
}

float GameSprite::GetMotionNumber() const
{
	return NumOfMotions;
}

float GameSprite::GetFrameWidth() const
//�׷��� �������� �ʺ�
{
	return FrameWidth;
}

float GameSprite::GetFrameHeight() const
//�׷��� �������� ����
{
	return FrameHeight;
}

void GameSprite::UpdateBuffers(ID3D10Device * deviceContext)
{
	// ���� �����Ӱ� ������ �������� ���. �Լ��� ���´�.
	HRESULT result;

	if (CurrentFrame == PreviousFrame) return;
	
	VertexType* vertices = GameBitmap::GetVertices();

	vertices[0].texture.x = CurrentFrame / MaxFrames;
	vertices[0].texture.y = CurrentMotion / NumOfMotions;

	vertices[1].texture.x = (CurrentFrame + 1.0) / MaxFrames;
	vertices[1].texture.y = (CurrentMotion + 1.0) / NumOfMotions;

	vertices[2].texture.x = CurrentFrame / MaxFrames;
	vertices[2].texture.y = (CurrentMotion + 1.0) / NumOfMotions;

	vertices[3].texture.x = CurrentFrame / MaxFrames;
	vertices[3].texture.y = CurrentMotion / NumOfMotions;

	vertices[4].texture.x = (CurrentFrame + 1.0) / MaxFrames;
	vertices[4].texture.y = CurrentMotion / NumOfMotions;

	vertices[5].texture.x = (CurrentFrame + 1.0) / MaxFrames;
	vertices[5].texture.y = (CurrentMotion + 1.0) / NumOfMotions;

	void* pVertices;
	result = m_vertexBuffer->Map(D3D10_MAP_WRITE_DISCARD, NULL, &pVertices);
	if (FAILED(result)) return;

	int verticesSize = sizeof(VertexType) * m_vertexCount;
	memcpy_s(pVertices, verticesSize, (void*)vertices, verticesSize);

	m_vertexBuffer->Unmap();

	PreviousFrame = CurrentFrame;
}
