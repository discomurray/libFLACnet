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
    }
}
