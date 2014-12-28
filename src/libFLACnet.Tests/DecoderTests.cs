namespace FLAC
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class DecoderTests
    {
        [TestMethod]
        public void Constructor_IsValid()
        {
            Decoder decoder = new Decoder();

            Assert.IsTrue(decoder.IsValid);
        }

        [TestMethod]
        public void GetState_IsNotNull()
        {
            Decoder decoder = new Decoder();

            Assert.IsNotNull(decoder.GetState());
        }

        [TestMethod]
        public void SetMetadataIgnore_StreamInfo()
        {
            MetadataType streamInfo = MetadataType.StreamInfo;

            Decoder decoder = new Decoder();
            decoder.SetMetadataIgnore(streamInfo);
        }

        [TestMethod]
        public void SetMetadataIgnoreAll()
        {
            Decoder decoder = new Decoder();
            decoder.SetMetadataIgnoreAll();
        }

        [TestMethod]
        public void SetMetadataIgnoreApplication()
        {
            MetadataId id = new MetadataId { byte1 = 0x00, byte2 = 0x00, byte3 = 0x00, byte4 = 0x00 };

            Decoder decoder = new Decoder();
            decoder.SetMetadataIgnoreApplication(id);
        }

        [TestMethod]
        public void SetMetadataRespond_StreamInfo()
        {
            Decoder decoder = new Decoder();

            MetadataType type = MetadataType.StreamInfo;
            decoder.SetMetadataRespond(type);
        }

        [TestMethod]
        public void SetMetadataRespondApplication()
        {
            MetadataId id = new MetadataId { byte1 = 0x00, byte2 = 0x00, byte3 = 0x00, byte4 = 0x00 };

            Decoder decoder = new Decoder();
            decoder.SetMetadataRespondApplication(id);
        }

        [TestMethod]
        public void SetMetadataRespondAll()
        {
            Decoder decoder = new Decoder();
            decoder.SetMetadataRespondAll();
        }

        [TestMethod]
        public void TotalSamples()
        {
            ulong expectedSamples = 0;

            Decoder decoder = new Decoder();
            Assert.AreEqual(decoder.TotalSamples, expectedSamples);
        }

        [TestMethod]
        public void Channels()
        {
            uint expectedChannels = 0;

            Decoder decoder = new Decoder();
            Assert.AreEqual(decoder.Channels, expectedChannels);
        }

        [TestMethod]
        public void ChannelAssignment()
        {
            ChannelAssignment assignment = FLAC.ChannelAssignment.Independent;

            Decoder decoder = new Decoder();
            Assert.AreEqual(decoder.ChannelAssignment, assignment);
        }
    }
}
