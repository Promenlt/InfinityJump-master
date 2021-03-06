#include "stdafx.h"
#include "Animation.h"

Animation::Animation(int id, vector<std::shared_ptr<Texture>> frames, int frameIndex)
{
	m_iID = id;
	m_frames = frames;
	m_iCurrentFrame = frameIndex;
	m_fTime = 0;
}

Animation::~Animation()
{
}

void Animation::setID(int id)
{
	m_iID = id;
}

void Animation::pushFrame(std::shared_ptr<Texture> frame)
{
	m_frames.push_back(frame);
}

void Animation::setSPF(GLfloat SPF)
{
	m_fSPF = SPF;
}

void Animation::setCurrentFrame(int frameIndex)
{
	m_iCurrentFrame = frameIndex;
}

void Animation::Pause()
{
	m_isStopped = true;
}

void Animation::Resume()
{
	m_isStopped = false;
}

int Animation::getID()
{
	return m_iID;
}

int Animation::getCountFrames() {
	return m_frames.size(); 
}

std::shared_ptr<Texture> Animation::getFrame(int index) {
	return ((index < (int) m_frames.size()) ? m_frames[index] : NULL); 
}

int Animation::getCurrentFrame() { 
	return m_iCurrentFrame; 
}

GLfloat Animation::getSPF() { 
	return m_fSPF; 
}

GLfloat Animation::getTime()
{
	return m_fTime;
}

void Animation::Init(int frameIndex)
{
	m_iCurrentFrame = frameIndex;
	m_fTime = 0;
}

void Animation::Update(GLfloat dt)
{
	if (!m_isStopped) {
		m_fTime += dt;
		if (m_fTime > m_fSPF) {
			m_iCurrentFrame += 1;
			if (m_iCurrentFrame >= getCountFrames()) {
				m_iCurrentFrame = 0;
			}
			m_fTime -= m_fSPF;
		}
	}
}
