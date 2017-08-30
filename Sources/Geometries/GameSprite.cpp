#include "GameSprite.h"

GameSprite::GameSprite(float framesPerSecond, float animationSpeed, bool isLooping) : GameBitmap()
{
	m_framesPerSecond = 1 / framesPerSecond;
	m_animationSpeed = animationSpeed;
	m_isLooping = isLooping;
	m_currentSpeed = 0;
	m_currentMotion = 0;
}

GameSprite::~GameSprite()
{
}

void GameSprite::Initialize(ID3D10Device *device, wchar_t *filePath, int bitmapWidth, int bitmapHeight, float numberOfMotions)
{
	m_currentFrame = 0;
	m_previousFrame = -1.0f;
	m_maxFrames = (float)bitmapWidth / (float)(bitmapHeight / numberOfMotions);
	m_numOfMotions = numberOfMotions;

	m_frameWidth = bitmapWidth / m_maxFrames;
	m_frameHeight = bitmapHeight / m_numOfMotions;

	GameBitmap::Initialize(device, filePath, bitmapWidth / m_maxFrames, bitmapHeight / numberOfMotions);
}

void GameSprite::Update(float dt)
{
	if (m_maxFrames == 1.0f) return;

	/*
		���濡 üũ�� ���� ������
		m_isLooping ���� �ʱ⿡ false ������ ������ �� ���Ƶ�
		������ �����ӱ��� ������Ʈ �ǰ� ������ �Ǳ� ������
		�ش� ��ġ�� �߰��ϰԵ�
	*/
	if (!m_isLooping)
	{
		m_currentFrame = m_maxFrames;
		return;
	}

	if (m_currentFrame <= m_maxFrames) {
		m_currentSpeed += m_animationSpeed * dt;

		if (m_currentSpeed > m_framesPerSecond) {
			m_currentFrame++;
			m_currentSpeed = 0;

			if (m_currentFrame >= m_maxFrames) {
				if (m_isLooping) {
					m_currentFrame = 0;
				}
				//�ʱ� üũ ��ġ
				//else {
				//	m_currentFrame = m_maxFrames;
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
	if (m_currentMotion != index)
	{
		m_currentMotion = index;
	}
}

void GameSprite::SetLooping(bool condition)
{
	if (m_isLooping != condition)
	{
		m_isLooping = condition;
	}
}

float GameSprite::GetMaxFrame() const
{
	return m_maxFrames;
}

float GameSprite::GetMotionNumber() const
{
	return m_numOfMotions;
}

float GameSprite::GetFrameWidth() const
//�׷��� �������� �ʺ�
{
	return m_frameWidth;
}

float GameSprite::GetFrameHeight() const
//�׷��� �������� ����
{
	return m_frameHeight;
}

void GameSprite::UpdateBuffers(ID3D10Device * deviceContext)
{
	// ���� �����Ӱ� ������ �������� ���. �Լ��� ���´�.
	HRESULT result;

	if (m_currentFrame == m_previousFrame) return;
	
	VertexType* vertices = GameBitmap::GetVertices();

	vertices[0].texture.x = m_currentFrame / m_maxFrames;
	vertices[0].texture.y = m_currentMotion / m_numOfMotions;

	vertices[1].texture.x = (m_currentFrame + 1.0) / m_maxFrames;
	vertices[1].texture.y = (m_currentMotion + 1.0) / m_numOfMotions;

	vertices[2].texture.x = m_currentFrame / m_maxFrames;
	vertices[2].texture.y = (m_currentMotion + 1.0) / m_numOfMotions;

	vertices[3].texture.x = m_currentFrame / m_maxFrames;
	vertices[3].texture.y = m_currentMotion / m_numOfMotions;

	vertices[4].texture.x = (m_currentFrame + 1.0) / m_maxFrames;
	vertices[4].texture.y = m_currentMotion / m_numOfMotions;

	vertices[5].texture.x = (m_currentFrame + 1.0) / m_maxFrames;
	vertices[5].texture.y = (m_currentMotion + 1.0) / m_numOfMotions;

	void* pVertices;
	result = m_vertexBuffer->Map(D3D10_MAP_WRITE_DISCARD, NULL, &pVertices);
	if (FAILED(result)) return;

	int verticesSize = sizeof(VertexType) * m_vertexCount;
	memcpy_s(pVertices, verticesSize, (void*)vertices, verticesSize);

	m_vertexBuffer->Unmap();

	m_previousFrame = m_currentFrame;
}
