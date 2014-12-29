namespace FLAC
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class StreamDecoderTests
    {
        [TestMethod]
        public void Constructor_IsValid()
        {
            StreamDecoder decoder = new StreamDecoder();

            Assert.IsTrue(decoder.IsValid);
        }

        [TestMethod]
        public void GetState_IsNotNull()
        {
            StreamDecoder decoder = new StreamDecoder();

            Assert.IsNotNull(decoder.GetState());
        }

        [TestMethod]
        public void SetMetadataIgnore_StreamInfo()
        {
            MetadataType streamInfo = MetadataType.StreamInfo;

            StreamDecoder decoder = new StreamDecoder();
            decoder.SetMetadataIgnore(streamInfo);
        }

        [TestMethod]
        public void SetMetadataIgnoreAll()
        {
            StreamDecoder decoder = new StreamDecoder();
            decoder.SetMetadataIgnoreAll();
        }

        [TestMethod]
        public void SetMetadataIgnoreApplication()
        {
            MetadataId id = new MetadataId { byte1 = 0x00, byte2 = 0x00, byte3 = 0x00, byte4 = 0x00 };

            StreamDecoder decoder = new StreamDecoder();
            decoder.SetMetadataIgnoreApplication(id);
        }

        [TestMethod]
        public void SetMetadataRespond_StreamInfo()
        {
            StreamDecoder decoder = new StreamDecoder();

            MetadataType type = MetadataType.StreamInfo;
            decoder.SetMetadataRespond(type);
        }

        [TestMethod]
        public void SetMetadataRespondApplication()
        {
            MetadataId id = new MetadataId { byte1 = 0x00, byte2 = 0x00, byte3 = 0x00, byte4 = 0x00 };

            StreamDecoder decoder = new StreamDecoder();
            decoder.SetMetadataRespondApplication(id);
        }

        [TestMethod]
        public void SetMetadataRespondAll()
        {
            StreamDecoder decoder = new StreamDecoder();
            decoder.SetMetadataRespondAll();
        }

        [TestMethod]
        public void TotalSamples()
        {
            ulong expectedSamples = 0;

            StreamDecoder decoder = new StreamDecoder();
            Assert.AreEqual(decoder.TotalSamples, expectedSamples);
        }

        [TestMethod]
        public void Channels()
        {
            uint expectedChannels = 0;

            StreamDecoder decoder = new StreamDecoder();
            Assert.AreEqual(decoder.Channels, expectedChannels);
        }

        [TestMethod]
        public void ChannelAssignment()
        {
            ChannelAssignment assignment = FLAC.ChannelAssignment.Independent;

            StreamDecoder decoder = new StreamDecoder();
            Assert.AreEqual(decoder.ChannelAssignment, assignment);
        }

        [TestMethod]
        public void BitsPerSample()
        {
            uint expectedBitsPerSample = 0;

            StreamDecoder decoder = new StreamDecoder();

            Assert.AreEqual(decoder.BitsPerSample, expectedBitsPerSample);
        }

        [TestMethod]
        public void SampleRate()
        {
            uint expectedSampleRate = 0;

            StreamDecoder decoder = new StreamDecoder();

            Assert.AreEqual(decoder.SampleRate, expectedSampleRate);
        }

        [TestMethod]
        public void BlockSize()
        {
            uint expectedBlockSize = 0;

            StreamDecoder decoder = new StreamDecoder();

            Assert.AreEqual(decoder.BlockSize, expectedBlockSize);
        }

        [TestMethod, ExpectedException(typeof(DecoderStreamException))]
        public void GetDecodePosition_Unintialized()
        {
            ulong expectedPosition = 0;

            StreamDecoder decoder = new StreamDecoder();

            Assert.AreEqual(decoder.GetDecodePosition(), expectedPosition);
        }

        [TestMethod]
        public void Initialize()
        {
            StreamDecoder decoder = new StreamDecoder();
            decoder.Initialize();
        }

        [TestMethod]
        public void InitializeOgg()
        {
            StreamDecoder decoder = new StreamDecoder();
            decoder.InitializeOgg();
        }

        [TestMethod]
        public void Finish()
        {
            StreamDecoder decoder = new StreamDecoder();
            decoder.Finish();
        }

        [TestMethod]
        public void Flush()
        {
            StreamDecoder decoder = new StreamDecoder();
            decoder.Flush();
        }

        [TestMethod]
        public void Reset()
        {
            StreamDecoder decoder = new StreamDecoder();
            decoder.Reset();
        }
    }
}
