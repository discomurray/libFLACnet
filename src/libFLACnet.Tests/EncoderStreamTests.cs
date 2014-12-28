namespace FLAC
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class EncoderStreamTests
    {
        [TestMethod]
        public void Construction_IsValid()
        {
            EncoderStream stream = new EncoderStream();

            Assert.IsTrue(stream.IsValid);
        }

        [TestMethod]
        public void Initialize()
        {
            EncoderStream stream = new EncoderStream();
            stream.Initialize();
        }

        [TestMethod]
        public void SetOggSerialNumber()
        {
            int serial = 12345;

            EncoderStream stream = new EncoderStream();
            stream.SetOggSerialNumber(serial);
        }

        [TestMethod]
        public void Verify_SetTrue()
        {
            EncoderStream stream = new EncoderStream();
            stream.Verify = true;
        }

        [TestMethod]
        public void Verify_SetFalse()
        {
            EncoderStream stream = new EncoderStream();
            stream.Verify = false;
        }

        [TestMethod]
        public void StreamableSubet_SetTrue()
        {
            EncoderStream stream = new EncoderStream();
            stream.StreamableSubset = true;
        }

        [TestMethod]
        public void StreamableSubet_SetFalse()
        {
            EncoderStream stream = new EncoderStream();
            stream.StreamableSubset = false;
        }

        [TestMethod]
        public void Channels_SetOne()
        {
            EncoderStream stream = new EncoderStream();
            stream.Channels = 1;
        }

        [TestMethod]
        public void Channels_SetTwo()
        {
            EncoderStream stream = new EncoderStream();
            stream.Channels = 2;
        }

        [TestMethod]
        public void BitsPerSample_SetEight()
        {
            EncoderStream stream = new EncoderStream();
            stream.BitsPerSample = 8;
        }

        [TestMethod]
        public void BitsPerSample_SetSixteen()
        {
            EncoderStream stream = new EncoderStream();
            stream.BitsPerSample = 16;
        }

        [TestMethod]
        public void SampleRate_Set44100()
        {
            EncoderStream stream = new EncoderStream();
            stream.SampleRate = 44100;
        }

        [TestMethod]
        public void SampleRate_Set39012()
        {
            EncoderStream stream = new EncoderStream();
            stream.SampleRate = 39012;
        }

        [TestMethod]
        public void SetCompressionLevel_SetZero()
        {
            EncoderStream stream = new EncoderStream();
            stream.SetCompressionLevel(0);
        }

        [TestMethod]
        public void SetCompressionLevel_SetMaximum()
        {
            EncoderStream stream = new EncoderStream();
            stream.SetCompressionLevel(uint.MaxValue);
        }

        [TestMethod]
        public void BlockSize_Set576()
        {
            EncoderStream stream = new EncoderStream();
            stream.BlockSize = 576;
        }

        [TestMethod]
        public void BlockSize_Set0()
        {
            EncoderStream stream = new EncoderStream();
            stream.BlockSize = 0;
        }
    }
}
