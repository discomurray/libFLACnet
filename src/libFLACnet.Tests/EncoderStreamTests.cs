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
    }
}
