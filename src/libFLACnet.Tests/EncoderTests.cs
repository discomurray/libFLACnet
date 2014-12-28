namespace FLAC
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class EncoderTests
    {
        [TestMethod]
        public void Construction_IsValid()
        {
            Encoder encoder = new Encoder(new MemoryStream());

            Assert.IsTrue(encoder.IsValid);
        }

        [TestMethod]
        public void Initialize()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.Initialize();
        }

        [TestMethod]
        public void SetOggSerialNumber()
        {
            int serial = 12345;

            Encoder encoder = new Encoder(new MemoryStream());
            encoder.SetOggSerialNumber(serial);
        }

        [TestMethod]
        public void Verify_SetTrue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.Verify = true;
        }

        [TestMethod]
        public void Verify_SetTrueInitialized()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.Verify = true;
            encoder.Initialize();

            Assert.IsTrue(encoder.Verify);
        }

        [TestMethod]
        public void Verify_SetFalse()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.Verify = false;
        }

        [TestMethod]
        public void StreamableSubet_SetTrue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.StreamableSubset = true;
        }

        [TestMethod]
        public void StreamableSubet_SetFalse()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.StreamableSubset = false;
        }

        [TestMethod]
        public void Channels_SetOne()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.Channels = 1;
        }

        [TestMethod]
        public void Channels_SetTwo()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.Channels = 2;
        }

        [TestMethod]
        public void BitsPerSample_SetEight()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.BitsPerSample = 8;
        }

        [TestMethod]
        public void BitsPerSample_SetSixteen()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.BitsPerSample = 16;
        }

        [TestMethod]
        public void SampleRate_Set44100()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.SampleRate = 44100;
        }

        [TestMethod]
        public void SampleRate_Set39012()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.SampleRate = 39012;
        }

        [TestMethod]
        public void SetCompressionLevel_SetZero()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.SetCompressionLevel(0);
        }

        [TestMethod]
        public void SetCompressionLevel_SetMaximum()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.SetCompressionLevel(uint.MaxValue);
        }

        [TestMethod]
        public void BlockSize_Set576()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.BlockSize = 576;
        }

        [TestMethod]
        public void BlockSize_Set0()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.BlockSize = 0;
        }

        [TestMethod]
        public void MidSideStereo_SetFalse()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.MidSideStereo = false;
        }

        [TestMethod]
        public void MidSideStereo_SetTrue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.MidSideStereo = true;
        }

        [TestMethod]
        public void LooseMidSideStereo_SetTrue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.LooseMidSideStereo = true;
        }

        [TestMethod]
        public void LooseMidSideStereo_SetFalse()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.LooseMidSideStereo = false;
        }

        [TestMethod]
        public void MaxLpcOrder_SetZero()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.MaxLpcOrder = 0;
        }

        [TestMethod]
        public void MaxLpcOrder_SetMaxValue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.MaxLpcOrder = uint.MaxValue;
        }

        [TestMethod]
        public void QlpCoeffPrecision_SetZero()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.QlpCoeffPrecision = 0;
        }

        [TestMethod]
        public void QlpCoeffPrecision_SetMaxValue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.QlpCoeffPrecision = uint.MaxValue;
        }

        [TestMethod]
        public void QlpCoeffPrecisionSearch_SetFalse()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.QlpCoeffPrecisionSearch = false;
        }

        [TestMethod]
        public void QlpCoeffPrecisionSearch_SetTrue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.QlpCoeffPrecisionSearch = true;
        }

        [TestMethod]
        public void EscapeCoding_SetFalse()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.EscapeCoding = false;
        }

        [TestMethod]
        public void EscapeCoding_SetTrue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.EscapeCoding = true;
        }

        [TestMethod]
        public void ExhaustiveModelSearch_SetFalse()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.ExhaustiveModelSearch = false;
        }

        [TestMethod]
        public void ExhaustiveModelSearch_SetTrue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.ExhaustiveModelSearch = true;
        }

        [TestMethod]
        public void ResidualPartitionOrderMinimum_SetZero()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.ResidualPartitionOrderMinimum = 0;
        }

        [TestMethod]
        public void ResidualPartitionOrderMinimum_SetMaxValue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.ResidualPartitionOrderMinimum = uint.MaxValue;
        }

        [TestMethod]
        public void ResidualPartitionOrderMaximum_SetZero()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.ResidualPartitionOrderMaximum = 0;
        }

        [TestMethod]
        public void ResidualPartitionOrderMaximum_SetMaxValue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.ResidualPartitionOrderMaximum = uint.MaxValue;
        }

        [TestMethod]
        public void TotalSamplesEstimate_SetZero()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.TotalSamplesEstimate = 0;
        }

        [TestMethod]
        public void TotalSamplesEstimate_SetMaxValue()
        {
            Encoder encoder = new Encoder(new MemoryStream());
            encoder.TotalSamplesEstimate = ulong.MaxValue;
        }
    }
}
