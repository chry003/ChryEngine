#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Base.hpp"
#include "Graphics/Shader.hpp"


namespace Chry 
{

    enum DrawType
    {
        STREAM = 0,
        STATIC = 1,
        DYNAMIC = 2
    };

    static GLenum DrawTypeToOpenGLType(DrawType vType)
    {
        switch(vType)
        {
            case DrawType::STREAM: return GL_STREAM_DRAW;
            case DrawType::STATIC: return GL_STATIC_DRAW;
            case DrawType::DYNAMIC: return GL_DYNAMIC_DRAW;
        }
        ASSERT(false, "Unknown Draw Type, EXPECTED: STREAM, STATIC, DYNAMIC");
    }

    //////////////////////////////////////
	//			Buffer Layout			//
	//////////////////////////////////////

	class BufferLayout
	{
	public:

		BufferLayout() {}

		BufferLayout(const silst<BufferElement>& elements)
			: m_Elements(elements)
		{
			CalcOffsetandStride();
		}

		inline const svec<BufferElement>& GetElements() const { return m_Elements; }

		inline const u32 GetStride() const { return m_Stride; }

		svec<BufferElement>::iterator begin() { return m_Elements.begin(); }
		svec<BufferElement>::iterator end() { return m_Elements.end(); }
		
		svec<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		svec<BufferElement>::const_iterator end() const { return m_Elements.end(); }

	private:
		void CalcOffsetandStride()
		{
			u32 offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}
	private:
		svec<BufferElement> m_Elements;
		u32 m_Stride = 0;
	};

    /////////////////////////////////
    //        Vertex Buffer        //
    /////////////////////////////////
    
    class VertexBuffer
    {
        public:
            VertexBuffer(float* vData, u32 vSize, const DrawType& vType);
            ~VertexBuffer();

            void Bind() const;
            void Unbind() const;
            void SetBufferLayout(const BufferLayout& vBufferLayout) { mBufferLayout = vBufferLayout; }

            inline BufferLayout GetBufferLayout() const { return mBufferLayout; }

        private:
            u32 mVertexBufferID;
            u32 mSize;
            BufferLayout mBufferLayout;
    };

    /////////////////////////////////
    //        Vertex Buffer        //
    /////////////////////////////////

    class IndexBuffer
    {
        public:
            IndexBuffer(usi* vData, u32 vCount, const DrawType& vType);
            IndexBuffer(u32* vData, u32 vCount, const DrawType& vType);
            ~IndexBuffer();

            void Bind() const;
            void Unbind() const;

            inline u32 GetCount() const { return mCount; }

        private:
            u32 mIndexBufferID;
            u32 mCount;
    };

    /////////////////////////////////
    //        Vertex Array         //
    /////////////////////////////////

    class VertexArray
    {
        public:
            VertexArray();
            ~VertexArray();

            void Bind() const;
            void Unbind() const;

            void AddVertexBuffer(const Ref<VertexBuffer>& vVertexBuffer);
            void SetIndexBuffer(const Ref<IndexBuffer>& vIndexBuffer);

            const svec<Ref<VertexBuffer>> GetVertexBuffer() const { return mVertexBuffers; }
            const Ref<IndexBuffer> GetIndexBuffer() const { return mIndexBuffer; }

        private:
            u32 mVertexArrayID;
            svec<Ref<VertexBuffer>> mVertexBuffers;
            Ref<IndexBuffer> mIndexBuffer;
    };
}
